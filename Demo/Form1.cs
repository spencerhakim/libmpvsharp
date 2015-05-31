using System;
using System.Diagnostics;
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

            _mpv = new Mpv(Handle);
            _mpv.LoadConfig("mpv.conf");
            _mpv.Initialize();

            var args = Environment.GetCommandLineArgs();
            if( args.Length > 1 )
            {
                _mpv.LoadFile(args[1]);
                Text = args[1];
            }

#if DEBUG
                //HACK - breaking here seems to fix an access violation when running in Debug mode.
                //Not sure why (race condition in MSVCRT?) but it doesn't happen in Release mode, so whatever.
                Debugger.Break();
#endif
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
