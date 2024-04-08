using CNVP.Framework.Helper;
using CNVP.Framework.Utils;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class PlugIn_NetWork_Honor_Index : System.Web.UI.Page
{
    public string PageNo = string.Empty;
    public string Action = string.Empty;
    public string Url = string.Empty;
    public string kw = string.Empty;
    public string typeId = string.Empty;
    public string FileName = "Index.aspx";

    protected void Page_Load(object sender, EventArgs e)
    {
        Action = Public.FilterSql(Request.Params['Action']);
        kw = Public.FilterSql(Request.Params['kw']);
        typeId = Public.FilterSql(Request.Params['typeId']);
        PageNo = Public.FilterSql(Request.Params['PageNo']);
        if (string.IsNullOrEmpty(PageNo) || !(Public.IsNumber(PageNo)))
        {
            PageNo = "1";
        }

        if (!IsPostBack)
        {
            Url = FileName + "?PageNo=" + PageNo + "&typeId=" + typeId;
            switch (Action)
            {
                case 'Del':
                    string[] IDs = Request.Params["ID"].Split(",");
                    foreach (string s in IDs)
                    {
                        if (!string.IsNullOrEmpty(s) || Public.IsNumber(s))
                            DbHelper.ExecuteNonQuery("delete from Honor where ID=" + s);
                    }

                    break;
                default:
                    break;
            }

            Location.Text = "<a href='/Plugin/NetWork/proSeriesClass/Index.aspx'>" + getParam(typeId) + "</a>";
            string StrWhere = "Honor where ParentID=" + typeId;
            if (!string.IsNullOrEmpty(kw))
            {
                StrWhere += "and ProTyTitle like '%" + kw + "%'";
            }

            int PageSize = 20;
            int RecordCount, PageCount;
            Repeater1.DataSource = DbHelper.ExecutePage("*", StrWhere, "ID", "Order By CreateTime Desc, ID Desc",
                Convert.ToInt32(PageNo), PageSize, out RecordCount, out PageCount);
            Repeater1.DataBind();
            LitPager.Text = DbHelper.GetPageGoogle(RecordCount, PageCount, PageSize, Convert.ToInt32(PageNo));
        }
    }

    public string getParam(string typeId)
    {
        string name = "";
        switch (typeId)
        {
            case "1":
                name = "个人";
                break;
            case "2":
                name = "集体";
                break;
            default:
                break;
        }

        return name;
    }

    public string getTime(string year, string month, string day)
    {
        string time = "";
        if (!string.IsNullOrEmpty(year))
        {
            if (!string.IsNullOrEmpty(month))
            {
                if (!string.IsNullOrEmpty(day))
                {
                    time = year + "-" + month + "-" + day;
                }
                else
                {
                    time = year + "-" + month;
                }
            }
            else
            {
                time = year;
            }
        }

        return time;
    }
}