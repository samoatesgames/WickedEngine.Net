using System;
using System.Windows;
using System.Windows.Media;

namespace WickedEngine.Net.WPF.Control
{
    public sealed class WickedEngineRenderView : Win32HwndControl
    {
        private bool m_rendering;
        public WickedEngineNet.WickedEngineNet WickedEngine { get; private set; }

        public WickedEngineRenderView()
        {
            WickedEngine = new WickedEngineNet.WickedEngineNet();

            // TODO: Set shader path via dependency property
            WickedEngine.SetShaderPath("Shaders/");
        }

        private void OwningWinder_Closing(object? sender, System.ComponentModel.CancelEventArgs e)
        {
            if (!m_rendering)
            {
                return;
            }
            Uninitialize();
        }

        protected override void Initialize()
        {
            var owningWinder = Window.GetWindow(this);
            owningWinder.Closing -= OwningWinder_Closing;
            owningWinder.Closing += OwningWinder_Closing;

            WickedEngine.SetWindow(Hwnd);
            WickedEngine.Run();

            m_rendering = true;
            CompositionTarget.Rendering += OnCompositionTargetRendering;
        }

        protected override void Uninitialize()
        {
            m_rendering = false;
            CompositionTarget.Rendering -= OnCompositionTargetRendering;
            WickedEngine.Shutdown();
        }

        protected override void OnWindowDestroyed()
        {
            WickedEngine.Shutdown();
        }

        protected override void Resized()
        {
            WickedEngine.OnWindowResize();
        }

        private void OnCompositionTargetRendering(object? sender, EventArgs eventArgs)
        {
            if (!m_rendering)
            {
                return;
            }
            WickedEngine.Run();
        }
    }
}
