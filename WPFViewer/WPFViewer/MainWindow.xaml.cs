using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WPFViewer
{
    /// <summary>
    /// MainWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private SerialPort serialPort;

        public void ArduinoOpen()
        {
            var port = textbox.Text;
            var COM = $"COM{port}";
            var Rate = 9600;
            var serialPort = new SerialPort(COM, Rate, Parity.None, 8, StopBits.One);
            serialPort.NewLine = Environment.NewLine; //改行コードを反映させない

            if (!serialPort.IsOpen) { serialPort.Open(); }
            else
            {
                MessageBox.Show("すでに開かれています");
                return;
            }

            serialPort.DataReceived += (s, e) =>
            {
                var Data = serialPort.ReadLine();
                textBlock.Text += Data;
            };
        }

        private void SerialOpen(object sender, RoutedEventArgs e)
        {
            try { ArduinoOpen(); }
            catch (Exception ex) { MessageBox.Show(ex.ToString()); }
        }

        private void SerialClose(object sender, RoutedEventArgs e)
        {
            if (!serialPort.IsOpen)
            {
                MessageBox.Show("ポートは開かれていません。");
                return;
            }
            else
            {
                try
                {
                    serialPort.Close();
                    MessageBox.Show("ポートを閉じました。");
                }
                catch (Exception ex) { MessageBox.Show(ex.ToString()); }
            }
        }
    }
}
     