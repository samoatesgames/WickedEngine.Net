using System;
using System.Numerics;
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

            var camera = engine.GetCamera();
            SetupCameraOrbit(camera);
        }

        private void SetupCameraOrbit(Camera camera)
        {
            var tick = 0.0f;
            void Timer_Elapsed(object? sender, System.Timers.ElapsedEventArgs e)
            {
                tick += 0.0025f;
                var x = MathF.Cos(tick) * 10.0f;
                var z = MathF.Sin(tick) * 10.0f;
                camera.SetPositionAndLookAt(new Vector3(x, 4, z), Vector3.Zero);
            }

            var timer = new System.Timers.Timer(20);
            timer.Elapsed += Timer_Elapsed;
            timer.Start();
        }
    }
}
