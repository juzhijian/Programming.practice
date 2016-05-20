using System;
using System.Windows.Forms;
using System.IO;

namespace 等级生成
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        //生成数据
        private void 按钮_生成_单击(object sender, EventArgs e)
        {
            string 首行 = "[/script/shootergame.shootergamemode]\n";
            //人物等级生成
            int x = int.Parse(编辑框_人物等级.Text);
            int z = int.Parse(编辑框_研究点数.Text);
            //恐龙等级生成
            int y = int.Parse(编辑框_恐龙等级.Text);
            //综合
            string 人物等级 = "LevelExperienceRampOverrides=(" + 等级函数(x) + ")\n";
            string 恐龙等级 = "LevelExperienceRampOverrides=(" + 等级函数(y) + ")\n";
            文本框_显示.Text = 首行 + "\n" + 玩家倍数函数() + "\n" + 恐龙倍数函数() + "\n" + 野生倍数函数() + "\n" + 人物等级 + 恐龙等级 + 研究点函数(x, z);
            //生成文件，"保存为"对话框
            SaveFileDialog dialog = new SaveFileDialog();
            dialog.Filter = "文本文件|*.ini";
            dialog.FileName = "Game";
            // 显示对话框
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                // 文件名
                string fileName = dialog.FileName;
                // 创建文件，准备写入
                FileStream fs = File.Open(fileName,
                        FileMode.Create,
                        FileAccess.Write);
                StreamWriter wr = new StreamWriter(fs);

                // 逐行将文本框_显示的内容写入到文件中
                foreach (string line in 文本框_显示.Lines)
                {
                    wr.WriteLine(line);
                }

                // 关闭文件
                wr.Flush();
                wr.Close();
                //fs.Close();
            }
        }
        //等级生成
        private string 等级函数(int a)
        {
            string 等级生成 = "ExperiencePointsForLevel[0]=10";
            int i;
            for (i = 1; i < a; i++)
            {
                等级生成 = 等级生成 + ",ExperiencePointsForLevel[" + i + "]=10";
            }
            return 等级生成;
        }
        //研究点数生成
        private string 研究点函数(int a,int b)
        {
            string 研究点生成= "OverridePlayerLevelEngramPoints="+b+"\n";
            int i;
            for (i = 1; i < a; i++)
            {
                研究点生成 = 研究点生成 + "OverridePlayerLevelEngramPoints=" + b + "\n";
            }
            return 研究点生成;
        }
        //玩家倍数生成
        private string 玩家倍数函数()
        {
            string 倍数生成 = 
                "PerLevelStatsMultiplier_Player[0]=" + int.Parse(编辑框_玩家_生命.Text) + "\n"+
                "PerLevelStatsMultiplier_Player[1]=" + int.Parse(编辑框_玩家_耐力.Text) + "\n"+
                "PerLevelStatsMultiplier_Player[2]=" + int.Parse(编辑框_玩家_麻痹.Text) + "\n"+
                "PerLevelStatsMultiplier_Player[3]=" + int.Parse(编辑框_玩家_氧气.Text) + "\n"+
                "PerLevelStatsMultiplier_Player[4]=" + int.Parse(编辑框_玩家_食物.Text) + "\n"+
                "PerLevelStatsMultiplier_Player[5]=" + int.Parse(编辑框_玩家_水.Text) + "\n" +
                "PerLevelStatsMultiplier_Player[6]=" + int.Parse(编辑框_玩家_温度.Text) + "\n" +
                "PerLevelStatsMultiplier_Player[7]=" + int.Parse(编辑框_玩家_负重.Text) + "\n" +
                "PerLevelStatsMultiplier_Player[8]=" + int.Parse(编辑框_玩家_伤害.Text) + "\n" +
                "PerLevelStatsMultiplier_Player[9]=" + int.Parse(编辑框_玩家_移动.Text) + "\n" +
                "PerLevelStatsMultiplier_Player[10]=" + int.Parse(编辑框_玩家_抗性.Text) + "\n" +
                "PerLevelStatsMultiplier_Player[11]=" + int.Parse(编辑框_玩家_制造.Text) + "\n";
            return 倍数生成;
        }
        //恐龙倍数生成
        private string 恐龙倍数函数()
        {
            string 倍数生成 =
                "PerLevelStatsMultiplier_DinoTamed[0]=" + int.Parse(编辑框_恐龙_生命.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoTamed[1]=" + int.Parse(编辑框_恐龙_耐力.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoTamed[2]=" + int.Parse(编辑框_恐龙_麻痹.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoTamed[3]=" + int.Parse(编辑框_恐龙_氧气.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoTamed[4]=" + int.Parse(编辑框_恐龙_食物.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoTamed[5]=" + int.Parse(编辑框_恐龙_水.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoTamed[6]=" + int.Parse(编辑框_恐龙_温度.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoTamed[7]=" + int.Parse(编辑框_恐龙_负重.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoTamed[8]=" + int.Parse(编辑框_恐龙_伤害.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoTamed[9]=" + int.Parse(编辑框_恐龙_移动.Text) + "\n";
            return 倍数生成;
        }
        //野生倍数生成
        private string 野生倍数函数()
        {
            string 倍数生成 =
                "PerLevelStatsMultiplier_DinoWild[0]=" + int.Parse(编辑框_野生_生命.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoWild[1]=" + int.Parse(编辑框_野生_耐力.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoWild[2]=" + int.Parse(编辑框_野生_麻痹.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoWild[3]=" + int.Parse(编辑框_野生_氧气.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoWild[4]=" + int.Parse(编辑框_野生_食物.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoWild[5]=" + int.Parse(编辑框_野生_水.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoWild[6]=" + int.Parse(编辑框_野生_温度.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoWild[7]=" + int.Parse(编辑框_野生_负重.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoWild[8]=" + int.Parse(编辑框_野生_伤害.Text) + "\n" +
                "PerLevelStatsMultiplier_DinoWild[9]=" + int.Parse(编辑框_野生_移动.Text) + "\n";
            return 倍数生成;
        }
        private void 倍数显示(object sender, EventArgs e)
        {
            //标签_玩家_生命.Text = "生命1X"+ int.Parse(textBox3.Text)*10+":";
        }
    }
}
