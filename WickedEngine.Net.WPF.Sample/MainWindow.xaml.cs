using System;
using System.Numerics;
using System.Windows;
using WickedEngineNet;

namespace WickedEngine.Net.WPF.Sample
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow
    {
        private Vector3 m_lookAt = Vector3.Zero;
        private float m_cameraYOffset = 6.0f;
        private float m_cameraDistance = 10.0f;

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
            LoadModel(engine);
        }

        private void LoadModel(WickedEngineNet.WickedEngineNet engine)
        {
            Entity? entity = null;
            if (!engine.TryLoadGLTF("Assets/FlightHelmet.glb", ref entity))
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
        }
    }
}
