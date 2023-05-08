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

            var weather = engine.GetWeather();
            weather.SetHorizon(new Vector3(0.38f, 0.38f, 0.38f));
            weather.SetZenith(new Vector3(0.42f, 0.42f, 0.42f));
            weather.SetAmbient(new Vector3(0.4f, 0.4f, 0.4f));

            var camera = engine.GetCamera();
            SetupCameraOrbit(camera);
        }

        private void SetupCameraOrbit(Camera camera)
        {
            var tick = -90.0f;
            void Timer_Elapsed(object? sender, System.Timers.ElapsedEventArgs e)
            {
                tick += 0.0025f;
                var x = MathF.Sin(tick) * 20.0f;
                var z = MathF.Cos(tick) * -20.0f;
                camera.SetPositionAndLookAt(new Vector3(x, 6, z), new Vector3(0, 0, 0));

                var position = (Vector3)camera.GetPosition();
                var lookAt = (Vector3)camera.GetForward();
                Application.Current?.Dispatcher?.InvokeAsync(() =>
                {
                    InfoTextBlock.Text = $"Camera Position: {position.X:F2},  {position.Y:F2},  {position.Z:F2}\n" +
                    $"Camera Forward: {lookAt.X:F2},  {lookAt.Y:F2},  {lookAt.Z:F2}";
                });
            }

            var timer = new System.Timers.Timer(20);
            timer.Elapsed += Timer_Elapsed;
            timer.Start();
        }

        private void RenderView_EngineInitialized(object sender, EventArgs e)
        {
            var engine = RenderView.WickedEngine;

            Entity? entity = default;
            if (!engine.TryLoadGLTF("Assets/DamagedHelmet.glb", ref entity))
            {
                throw new Exception("Failed to load GLTF model");
            }

            // TODO: use the bounds to calculate optimal scale and translation
            var transform = entity.GetTransform();
            transform.SetTranslation(new Vector3(0, 4, 0));
            transform.SetScale(new Vector3(4, 4, 4));
        }
    }
}
