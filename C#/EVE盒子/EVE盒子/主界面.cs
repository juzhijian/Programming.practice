using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EVE盒子
{
    public partial class 主界面 : Form
    {
        public 主界面()
        {          
            InitializeComponent();
            //临时数据
            int t = 12546578;
            this.标签_技能点数_数字.Text = t.ToString("N");
        }

        private void 按钮_编辑角色_单击(object sender, EventArgs e)
        {
            //打开技能设置
            if (布局_人物设置_技能.Visible == false)
            {
                布局_人物设置_技能.Visible = true;
            }
            else if(布局_人物设置_技能.Visible == true)
            {
                布局_人物设置_技能.Visible = false;
            }
        }
    }
}
