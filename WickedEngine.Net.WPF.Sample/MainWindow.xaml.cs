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
            engine.SetInfoDisplay(WickedEngineNet.InfoDisplay.Active, true);
            engine.SetInfoDisplay(WickedEngineNet.InfoDisplay.Watermark, true);
            engine.SetInfoDisplay(WickedEngineNet.InfoDisplay.FpsInfo, true);
            engine.SetInfoDisplay(WickedEngineNet.InfoDisplay.Resolution, true);

            var renderPath = engine.GetRenderPath();
            renderPath.SetHelperGridEnabled(true);
            renderPath.SetSSREnabled(true);
        }
    }
}
