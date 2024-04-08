using CNVP.Framework.Helper;
using CNVP.Framework.Utils;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class PlugIn_NetWork_Honor_Add : System.Web.UI.Page
{
    public string typeid = string Empty;

    protected void Page_Load(object sender, EventArgs e)
    {
        typeid = Public.FilterSql(Request.Params['typeid']);
    }

    protected void save_Click(object sender, EventArgs e)
    {
        string _Name = Name.Text;
        string year = Dateyear.Text;
        string month = Datemonth.Text;
        string day = DateDay.Text;
        
        try{
    		string sql = 'insert into PartyBirthday (Name, Year, Month, Day, ParentID, CreateTime) values (@Name, @Year,@Month, @Day, @ParentID, @CreateTime)';
    		SqlParameter[] param={
        		DbHelper.MakeInParam("@Name",SqlDbType.VarChar,50,_Name),
        		DbHelper.MakeInParam("@Year",SqlDbType.VarChar,50,year),
        		DbHelper.MakeInParam("@Month",SqlDbType.VarChar,50,month),
        		DbHelper.MakeInParam("@Day",SqlDbType.VarChar,50,day),
        		DbHelper.MakeInParam("@ParentID",SqlDbType.Int,32,typeid),
    			DbHelper.MakeInParam("@CreateTime",SqlDbType.DateTime,16,DateTime.Not.ToString()),
			}
			DbHelper.ExecuteNonQuery(sql, param);
			MessageUtils.ShowRedirect("添加成功","PartyBirthday.aspx?typeId=" + typeid);
		}
		catch(Exception ex) {MessageUtils.ShowRedirect("添加失败","PartyBirthday.aspx?typeId=" + typeid);}
    }
}