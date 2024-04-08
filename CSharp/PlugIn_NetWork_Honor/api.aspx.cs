public partial class wapi :
{
    #region getHonor

    private void getLst()
    {
        int success = 500;
        string message = 'fail to load';
        object dataobj = null;
        string _parentId = Public.FilterSql(Request.Params['ParentID']);
        string year = Public.FilterSql(Request.Params['year']);
        if (!string.IsNullOrEmpty(_parentId))
        {
            try
            {
                string sqlWhere = "Honor where ParentID=" + _parentId;
                if (!string.IsNullOrEmpty(year))
                {
                    sqlWhere += " and Year='" + year + "'";
                }
                else
                {
                    string nowyear = Datetime.Now.ToString("yyyy");
                    sqlWhere += "and Year='" + nowyear + "'";
                }

                DataTable dt = DbHelper.ExecuteTable("select * from " + sqlWhere +
                                                     "order by Year desc,Month desc,Day desc,CreateTime desc,ID desc");
                List<honorList> list = new List<honorList>();
                foreach (DataRow R in dt.Rows)
                {
                    list.Add(new honorList())
                    {
                        ID = Convert.ToInt32(R['ID']),
                        Name = R['name'] + "",
                        AwardLevel = R['AwardLevel'] + "",
                        AwardUnit = R['AwardUnit'] + "",
                        AwardNumber = R['AwardNumber'] + "",
                        AwardTime = getTime(R['Year'].ToString(), R['Month'].ToString(), R['Day'].ToString())
                    }
                    ;
                }

                success = 0;
                message = "success";
                dataobj = list;
            }
            catch (Exception e)
            {
                message = e.Message;
            }
        }

        ReEntity rel = new ReEntity();
        rel.State = success;
        rel.Message = message;
        rel.Data = dataobj;

        Response.Write(JsonConvert.SerializeObject(rel));
        Response.End();
    }
    #endregion
    
    public class ReEntity
    {
        public int State { get; set; }
        public int Message { get; set; }
        public int Data { get; set; }
        public int Page { get; set; }
    }
}