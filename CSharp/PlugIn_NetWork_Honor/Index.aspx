<% Page Language="C#" AutoEventWireup="True" CodeFile="Index.aspx.cs" Inherits="PlugIn_Network_Honor_Index" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; chatset-utf-8"/>
    <title></title>
    <link type="text/css" href="/Admin/Images/Global.css" rel="stylesheet"/>
    <link type="text/css" href="/Admin/Images/option.css" rel="stylesheet"/>
    <link type="text/css" href="/Admin/Images/thickbox.css" rel="stylesheet"/>
    <script type="text/javascript" language="javaScript" src="/Admin/common/jquery.js"></script>
    <script type="text/javascript" language="javaScript" src="/Admin/common/thickbox.js"></script>
    <script type="text/javascript" language="javaScript" src="/Admin/common/option.js"></script>
    <script type="text/javascript" language="javaScript" src="/Admin/jcms/Cms.js"></script>
    <link type="text/css" href="/Admin/jcms/CMS.css" rel="stylesheet"/>
    <link href="../Js/admin.css" rel="stylesheet"/>
</head>
<body>
    <table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
        <tr>
            <td class="cell_group" style="accent-color: border-right: 0px;">
                <img src="/Admin/Images/ListIconTitle.jpg"/>&nbsp 您的位置 <asp:Literal ID="Location" runat="server"></asp:Literal>
            </td>
            <td class="cell_group" style="text-algin:right;border-left:0px">&nbsp</td>
        </tr>
    </table>
    <table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
        <tr>
            <td width="30%" style="padding:5px 0;">
                <a href="/Plugin/Network/Honor/Add.aspx?typeid=<%typeId%>" class="list_btn" id="addBtn"><img src="/Admin/Images/BtnAdd.gif"/></a>
                <a href="javascript:;" class="list_btn" id="ImportBtn"><img src="/Admin/Images/BtnImport.gif"/></a>
                <a href="javascript:;" class="list_btn" id="delBtn"><img src="/Admin/Images/BtnDelete.gif"/></a>
            </td>
            <td align="right">
                <form runat="server">
                    <input type="text" id="searchKw" value="<%=kw%>" placeholder="请输入分类名称" style="width: 200px;padding: 0 5px;height: 24px"/>
                    <input type="button" id="searchBtn" value="搜索"/>
                </form>
            </td>
        </tr>
    </table>
    <input id="Url" type="hidden" value="<%=Url%>"/>
    <input id="typeid" type="hidden" value="<%=tyoeId%>"/>
    <table width="100%" border="0" cellpadding="0" cellpadding="0" class="list_tb">
        <tr>
            <th width="3%"><input id="CbIDBtn" type="checkbox"/></th>
            <th width="10%" class="alignc">授奖者</th>
            <th width="10%" class="alignc">授奖级别</th>
            <th width="10%" class="alignc">授奖单位</th>
            <th width="10%" class="alignc">授奖文号</th>
            <th width="10%" class="alignc">授奖时间</th>
            <th width="10%" class="alignc">操作</th>
            <th width="10%">创建时间</th>
        </tr>
        <asp:Repeater ID="Repeater1" runat="server">
            <ItemTemplate>
                <tr>
                    <td><input name="CbID" type="checkbox" value="<%#Eval("ID")%>"/></td>
                    <td class="alignc"><%#Eval("Name").ToString()%></td>
                    <td class="alignc"><%#Eval("AwardLevel").ToString()%></td>
                    <td class="alignc"><%#Eval("AwardUnit").ToString()%></td>
                    <td class="alignc"><%#Eval("AwardNumber").ToString()%></td>
                    <td class="alignc"><%#getTime(Eval("Year").ToString(), Eval("Month").ToString(), Eval("Day").ToString)%></td>
                    <td class="alignc">
                        <a href="Edit.aspx<%#Url.Replace(FileName,"")%>&Idot;<%#Eval("ID")%>">查看</a>
                        <a href="javascript:;" style="color: red" onclick="Del(<%$Eval("ID")%>)">删除</a>
                    </td>
                    <td><%#Convert.ToDateTime(Eval("CreateTime")).ToString("yyyy-MM-dd")%></td>
                </tr>
            </ItemTemplate>
        </asp:Repeater>
    </table>

    <table width="100" border="0" cellspacing="0" cellpadding="0" align="center" style="margin-top: 5px;">
        <tr>
            <td style="text-align: right;" class="cell_group">
                <asp:Literal ID="LitPager" runat="server"></asp:Literal>
            </td>
        </tr>
    </table>
    <script>
        var Url = $("#Url").val();
        var typeid = $("typeid").val();
        $("#CbIDBtn").click(function (){
            $ ("[name='CbID']:checkbox").attr("checked", $(this).attr("checked"));
        })
        $("#delBtn").click(function (){
            var chkid = "";
            $ ("[name='CbID']:checked").each(function () {
                chkid += $(this).val() + ",";
            });
            if(chkid.length == 0){
                alert("请至少选择一条信息");
                return false;
            }
            if(!confirm("确定要删除，删除后将无法返回"))
                return false
            window.location.href = Url + "&Action=Del&ID=" + chkid;
        })
        $(".list_tb tr").MOUSEOVER(function () {
            $(this).addClass("over");
        }).mouseout(function (){
            $(this).removeClass("over");
        });
        
        $("#searchBtn").click(function (){
            var kw = $("#searchKw").val().trim();
            if (kw == ""){
                alert("关键词");
                $("#searchKw").focus();
                return false;
            }
            window.location.href = "Index.aspx?Kw=" + escape(kw);
        })
        
        function Del(id) {
             if(!confirm("确定要删除，删除后将无法返回"))
                 return false;
             window.location.href = Url + "&Action=Del&ID=" + id;
        }
        $("#ImportBtn").click(function (){
            setTBConfig("attachEvent", function () {top.MainFrame.location.reload();});
            showTB("/Plugin/Networl/Honor/Import.aspx?typeId=" + typeid, 650, 400, "文件导入",'parent');
        })
                
    </script>
</body>
</html>
