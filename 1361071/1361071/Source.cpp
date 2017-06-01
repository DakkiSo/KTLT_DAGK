#include<stdio.h>
#include<conio.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<wchar.h>

struct Student{
	char MSSV[10];
	wchar_t Ten[30];
	wchar_t Khoa[30];
	int KhoaTuyen;
	char NgaySinh[11];
	wchar_t Hinhanh[1000];
	wchar_t Motabanthan[1000];
	wchar_t Sothich1[1000];
	wchar_t Sothich2[1000];
};

void vietfile()
{
	wchar_t filename[60];
	FILE* fo = _wfopen(filename, L"wt");
	fwprintf(fo, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	fwprintf(fo, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
	fwprintf(fo, L"	<head>\n");
	fwprintf(fo, L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
	fwprintf(fo, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
	//--%ls--
	fwprintf(fo, L"		<title>HCMUS - %ls</title>\n");
	fwprintf(fo, L"	</head>\n");
	fwprintf(fo, L"	<body>\n");
	fwprintf(fo, L"		<div class=\"Layout_container\">\n");
	fwprintf(fo, L"			<!-- Begin Layout Banner Region -->\n");
	fwprintf(fo, L"			<div class=\"Layout_Banner\" >\n");
	fwprintf(fo, L"				<div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
	fwprintf(fo, L"				<div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"			<!-- End Layout Banner Region -->\n");
	fwprintf(fo, L"			<!-- Begin Layout MainContents Region -->\n");
	fwprintf(fo, L"			<div class=\"Layout_MainContents\">\n");
	fwprintf(fo, L"				<!-- Begin Below Banner Region -->\n");
	fwprintf(fo, L"				<div class=\"Personal_Main_Information\">\n");
	fwprintf(fo, L"					<!-- Begin Thông tin cá nhân của sinh viên ----------------------------------------------------------------------------------------- -->\n");
	fwprintf(fo, L"					<div class=\"Personal_Location\"> \n");
	fwprintf(fo, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
	//--%ls--
	fwprintf(fo, L"						<span class=\"Personal_FullName\">%ls - %ls</span>\n");
	fwprintf(fo, L"						<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"						<div class=\"Personal_Phone\">\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"					<!-- End Thông tin cá nhân của sinh viên ----------------------------------------------------------------------------------------- -->\n");
	fwprintf(fo, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
	//--%ls--
	fwprintf(fo, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n");
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"				<!-- End Below Banner Region -->\n");
	fwprintf(fo, L"				<!-- Begin MainContents Region -->\n");
	fwprintf(fo, L"				<div class=\"MainContain\">\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"					<!-- Begin Top Region -->\n");
	fwprintf(fo, L"					<div class=\"MainContain_Top\">\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"						<div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
	fwprintf(fo, L"                       <div>\n");
	fwprintf(fo, L"                            <ul class=\"TextInList\">\n");
	//--%ls--
	fwprintf(fo, L"                              <li>Họ và tên: %ls </li>\n");
	fwprintf(fo, L"								 <li>MSSV: %ls </li>\n");
	fwprintf(fo, L"								 <li>Sinh viên khoa %ls </li>\n");
	fwprintf(fo, L"								 <li>Ngày sinh: %ls </li>\n");
	fwprintf(fo, L"							 </ul>\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"                       <div class=\"InfoGroup\">Sở thích</div>\n");
	fwprintf(fo, L"                       <div>\n");
	fwprintf(fo, L"                            <ul class=\"TextInList\">\n");
	//--%ls--
	fwprintf(fo, L"                              <li>%ls</li>\n");
	fwprintf(fo, L"								 <li>%ls</li>\n");
	fwprintf(fo, L"							 </ul>\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
	fwprintf(fo, L"						<div class=\"Description\">\n");
	//--%ls--
	fwprintf(fo, L"                            %ls.\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"\n");
	fwprintf(fo, L"			<!-- Begin Layout Footer -->\n");
	fwprintf(fo, L"			<div class=\"Layout_Footer\">\n");
	fwprintf(fo, L"				<div class=\"divCopyright\">\n");
	fwprintf(fo, L"					<br />\n");
	fwprintf(fo, L"					<img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
	fwprintf(fo, L"					<br />\n");
	fwprintf(fo, L"				@2017</br>\n");
	fwprintf(fo, L"				Đồ án giữa kì</br>\n");
	fwprintf(fo, L"				Kỹ thuật lâp trình</br>\n");
	fwprintf(fo, L"				TH2017/06</br>\n");
	fwprintf(fo, L"				1361071 - Lâm Hưng Phát</br>\n");
	fwprintf(fo, L"				</div>\n");
	fwprintf(fo, L"			</div>\n");
	fwprintf(fo, L"			<!-- End Layout Footer -->\n");
	fwprintf(fo, L"		</div>\n");
	fwprintf(fo, L"	</body>\n");
	fwprintf(fo, L"</html>");
	fclose(fo);
	fclose(fo);
}

void main()
{
	
}