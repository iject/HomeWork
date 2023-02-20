namespace Paint
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            panel1 = new Panel();
            comboBox1 = new ComboBox();
            trackBar1 = new TrackBar();
            btncolor = new Button();
            btnfill = new Button();
            btnline = new Button();
            btnrect = new Button();
            btnellipse = new Button();
            btneraser = new Button();
            btnpen = new Button();
            Pic = new PictureBox();
            panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)trackBar1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)Pic).BeginInit();
            SuspendLayout();
            // 
            // panel1
            // 
            panel1.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            panel1.BackColor = SystemColors.ActiveCaption;
            panel1.BackgroundImage = (Image)resources.GetObject("panel1.BackgroundImage");
            panel1.BackgroundImageLayout = ImageLayout.Stretch;
            panel1.Controls.Add(comboBox1);
            panel1.Controls.Add(trackBar1);
            panel1.Controls.Add(btncolor);
            panel1.Controls.Add(btnfill);
            panel1.Controls.Add(btnline);
            panel1.Controls.Add(btnrect);
            panel1.Controls.Add(btnellipse);
            panel1.Controls.Add(btneraser);
            panel1.Controls.Add(btnpen);
            panel1.Location = new Point(0, 0);
            panel1.Margin = new Padding(3, 4, 3, 4);
            panel1.Name = "panel1";
            panel1.Size = new Size(912, 103);
            panel1.TabIndex = 0;
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Items.AddRange(new object[] { "Cплошная линия", "Штрих", "Точка", "Штрих-пунктир", "Штрих-две точки" });
            comboBox1.Location = new Point(591, 65);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(151, 28);
            comboBox1.TabIndex = 9;
            comboBox1.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            // 
            // trackBar1
            // 
            trackBar1.BackColor = Color.White;
            trackBar1.Location = new Point(575, 3);
            trackBar1.Maximum = 20;
            trackBar1.Name = "trackBar1";
            trackBar1.Size = new Size(181, 56);
            trackBar1.TabIndex = 7;
            trackBar1.Value = 10;
            trackBar1.ValueChanged += trackBar1_ValueChanged;
            // 
            // btncolor
            // 
            btncolor.BackColor = Color.Transparent;
            btncolor.FlatStyle = FlatStyle.Popup;
            btncolor.Image = (Image)resources.GetObject("btncolor.Image");
            btncolor.Location = new Point(804, 16);
            btncolor.Margin = new Padding(3, 4, 3, 4);
            btncolor.Name = "btncolor";
            btncolor.Size = new Size(70, 70);
            btncolor.TabIndex = 6;
            btncolor.UseVisualStyleBackColor = false;
            btncolor.Click += btncolor_Click;
            // 
            // btnfill
            // 
            btnfill.Image = (Image)resources.GetObject("btnfill.Image");
            btnfill.Location = new Point(486, 21);
            btnfill.Margin = new Padding(3, 4, 3, 4);
            btnfill.Name = "btnfill";
            btnfill.Size = new Size(60, 60);
            btnfill.TabIndex = 5;
            btnfill.UseVisualStyleBackColor = true;
            btnfill.Click += btnfill_Click;
            // 
            // btnline
            // 
            btnline.Image = (Image)resources.GetObject("btnline.Image");
            btnline.Location = new Point(395, 21);
            btnline.Margin = new Padding(3, 4, 3, 4);
            btnline.Name = "btnline";
            btnline.Size = new Size(60, 60);
            btnline.TabIndex = 4;
            btnline.UseVisualStyleBackColor = true;
            btnline.Click += btnline_Click;
            // 
            // btnrect
            // 
            btnrect.Image = (Image)resources.GetObject("btnrect.Image");
            btnrect.Location = new Point(304, 21);
            btnrect.Margin = new Padding(3, 4, 3, 4);
            btnrect.Name = "btnrect";
            btnrect.Size = new Size(60, 60);
            btnrect.TabIndex = 3;
            btnrect.UseVisualStyleBackColor = true;
            btnrect.Click += btnrect_Click;
            // 
            // btnellipse
            // 
            btnellipse.Image = (Image)resources.GetObject("btnellipse.Image");
            btnellipse.Location = new Point(213, 21);
            btnellipse.Margin = new Padding(3, 4, 3, 4);
            btnellipse.Name = "btnellipse";
            btnellipse.Size = new Size(60, 60);
            btnellipse.TabIndex = 2;
            btnellipse.UseVisualStyleBackColor = true;
            btnellipse.Click += btnellipse_Click;
            // 
            // btneraser
            // 
            btneraser.Image = (Image)resources.GetObject("btneraser.Image");
            btneraser.Location = new Point(122, 21);
            btneraser.Margin = new Padding(3, 4, 3, 4);
            btneraser.Name = "btneraser";
            btneraser.Size = new Size(60, 60);
            btneraser.TabIndex = 1;
            btneraser.UseVisualStyleBackColor = true;
            btneraser.Click += btneraser_Click;
            // 
            // btnpen
            // 
            btnpen.Image = (Image)resources.GetObject("btnpen.Image");
            btnpen.Location = new Point(31, 21);
            btnpen.Margin = new Padding(3, 4, 3, 4);
            btnpen.Name = "btnpen";
            btnpen.Size = new Size(60, 60);
            btnpen.TabIndex = 0;
            btnpen.UseVisualStyleBackColor = true;
            btnpen.Click += btnpen_Click;
            // 
            // Pic
            // 
            Pic.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            Pic.Location = new Point(0, 105);
            Pic.Margin = new Padding(3, 4, 3, 4);
            Pic.Name = "Pic";
            Pic.Size = new Size(912, 492);
            Pic.TabIndex = 1;
            Pic.TabStop = false;
            Pic.Paint += Pic_Paint;
            Pic.MouseClick += Pic_MouseClick;
            Pic.MouseDown += Pic_MouseDown;
            Pic.MouseMove += Pic_MouseMove;
            Pic.MouseUp += Pic_MouseUp;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(914, 600);
            Controls.Add(Pic);
            Controls.Add(panel1);
            Margin = new Padding(3, 4, 3, 4);
            Name = "Form1";
            Text = "paint...";
            Load += Form1_Load;
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)trackBar1).EndInit();
            ((System.ComponentModel.ISupportInitialize)Pic).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private Panel panel1;
        private Button btnpen;
        private PictureBox Pic;
        private Button btneraser;
        private Button btnellipse;
        private Button btnrect;
        private Button btnline;
        private Button btnfill;
        private Button btncolor;
        private TrackBar trackBar1;
        private ComboBox comboBox1;
    }
}