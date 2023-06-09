﻿using System;
using System.Numerics;
using System.Windows;
using System.Windows.Controls;
using WickedEngineNet;

namespace WickedEngine.Net.WPF.Sample
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow
    {
        private Entity? m_entity = null;
        private Vector3 m_lookAt = Vector3.Zero;
        private float m_cameraYOffset = 6.0f;
        private float m_cameraDistance = 10.0f;
        private Entity? m_skyLightEntity = null;

        public MainWindow()
        {
            InitializeComponent();

            var engine = RenderView.WickedEngine;
            engine.SetInfoDisplay(InfoDisplay.Active, true);
            engine.SetInfoDisplay(InfoDisplay.Watermark, true);
            engine.SetInfoDisplay(InfoDisplay.FpsInfo, true);
            engine.SetInfoDisplay(InfoDisplay.Resolution, true);

            var renderPath = engine.GetRenderPath();
            renderPath.SetHelperGridEnabled(true);
            renderPath.SetSSREnabled(true);
            renderPath.SetTemporalAAEnabled(true);

            var weather = engine.GetWeather();
            weather.SetHorizon(new Vector3(0.38f, 0.38f, 0.38f));
            weather.SetZenith(new Vector3(0.42f, 0.42f, 0.42f));
            weather.SetAmbient(new Vector3(0.4f, 0.4f, 0.4f));

            var camera = engine.GetCamera();
            SetupCameraOrbit(camera);
        }

        private void SetupCameraOrbit(Camera camera)
        {
            var tick = -75.0f;
            void Timer_Elapsed(object? sender, System.Timers.ElapsedEventArgs e)
            {
                tick += 0.0025f;
                var x = MathF.Sin(tick) * m_cameraDistance;
                var z = MathF.Cos(tick) * -m_cameraDistance;
                camera.SetPositionAndLookAt(new Vector3(x, m_cameraYOffset, z), m_lookAt);

                var position = (Vector3)camera.GetPosition();
                var lookDir = (Vector3)camera.GetForward();
                Application.Current?.Dispatcher?.InvokeAsync(() =>
                {
                    InfoTextBlock.Text = $"Camera Position: {position.X:F2},  {position.Y:F2},  {position.Z:F2}\n" +
                    $"Camera Forward: {lookDir.X:F2},  {lookDir.Y:F2},  {lookDir.Z:F2}";
                });
            }

            var timer = new System.Timers.Timer(20);
            timer.Elapsed += Timer_Elapsed;
            timer.Start();
        }

        private void RenderView_EngineInitialized(object sender, EventArgs e)
        {
            var engine = RenderView.WickedEngine;

            SetupSkyLight(engine);
            LoadModel(engine);
        }

        private void SetupSkyLight(WickedEngineNet.WickedEngineNet engine)
        {
            engine.DestroyEntity(ref m_skyLightEntity);

            m_skyLightEntity = engine.CreateLight(LightType.Directional);
            var light = m_skyLightEntity.GetLight();
            light.SetIntensity((float)LightIntensity.Value);
            light.SetCastShadow(LightShadows.IsChecked == true);
            light.SetColor(new Vector3((float)LightColorR.Value, (float)LightColorG.Value, (float)LightColorB.Value));
        }

        private void AssetComboBox_SelectionChanged(object sender, System.Windows.Controls.SelectionChangedEventArgs e)
        {
            var engine = RenderView.WickedEngine;
            LoadModel(engine);
        }

        private void LoadModel(WickedEngineNet.WickedEngineNet engine)
        {
            if (!engine.IsInitialized())
            {
                return;
            }

            var modelPath = (string)((ComboBoxItem)AssetComboBox.SelectedItem).Content;

            Entity? entity = null;
            engine.DestroyEntity(ref m_entity);
            if (!engine.TryLoadGLTF(modelPath, ref entity))
            {
                throw new Exception("Failed to load GLTF model");
            }

            const float targetScale = 8.0f;

            var bounds = entity.GetBounds();
            var y = ((Vector3)bounds.GetMin()).Y;
            var scale = targetScale / bounds.GetRadius();

            var yOffset = -y * scale;

            var transform = entity.GetTransform();
            transform.SetTranslation(new Vector3(0, yOffset, 0));
            transform.SetScale(new Vector3(scale, scale, scale));

            m_lookAt = ((Vector3)bounds.GetCenter()) * scale;
            m_lookAt.Y += yOffset;

            m_cameraYOffset = m_lookAt.Y * 1.5f;
            m_cameraDistance = (bounds.GetRadius() * 1.75f) * scale;

            m_entity = entity;
        }

        private void LightShadows_Checked(object sender, RoutedEventArgs e)
        {
            var light = m_skyLightEntity?.GetLight();
            if (light == null)
            {
                return;
            }
            light.SetCastShadow(LightShadows.IsChecked == true);
        }

        private void LightIntensity_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            var light = m_skyLightEntity?.GetLight();
            if (light == null)
            {
                return;
            }
            light.SetIntensity((float)LightIntensity.Value);
        }

        private void LightColor_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            var light = m_skyLightEntity?.GetLight();
            if (light == null)
            {
                return;
            }
            light.SetColor(new Vector3((float)LightColorR.Value, (float)LightColorG.Value, (float)LightColorB.Value));
        }
    }
}
