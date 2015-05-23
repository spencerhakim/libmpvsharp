using System.Windows.Forms;
using libmpvsharp;

namespace Demo
{
    public partial class Form1 : Form
    {
        private Mpv _mpv;

        public Form1()
        {
            InitializeComponent();

            Shown += (sender, args) =>
            {
                _mpv = new Mpv(Handle);
                _mpv.LoadConfig(@"C:\Users\Spencer H\Documents\Visual Studio 2013\Projects\D3Player7\D3.Core\Resources\mpv.conf");
                _mpv.Initialize();
                _mpv.LoadFile(@"C:\Users\Spencer H\Desktop\Halo Reach 720p.mp4");
            };
        }

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if( disposing && (components != null) )
            {
                components.Dispose();
            }

            if( disposing && _mpv != null )
                _mpv.Dispose();

            base.Dispose(disposing);
        }
    }
}
