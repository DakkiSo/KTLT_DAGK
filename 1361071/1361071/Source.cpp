#include<stdio.h>
#include<conio.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<wchar.h>

struct Student{
	wchar_t MSSV[10];
	wchar_t Ten[30];
	wchar_t Khoa[30];
	int KhoaTuyen;
	wchar_t NgaySinh[11];
	wchar_t Hinhanh[1000];
	wchar_t Motabanthan[1000];
	wchar_t Sothich1[1000];
	wchar_t Sothich2[1000];
};

wchar_t** TaoMang(FILE *f, int &n)
{
	n = 0;
	wchar_t **a = (wchar_t**)malloc(1 * sizeof(wchar_t*));
	while (!feof(f))
	{
		a[n] = (wchar_t*)malloc(1600 * sizeof(wchar_t));
		fgetws(a[n], 1600, f);
		if (!feof(f))
		{
			n++;
			a = (wchar_t**)realloc(a, (n + 1)*sizeof(wchar_t*));
		}
		else
			break;
	}
	return a;
}

void chuyen(wchar_t *b, wchar_t a[])
{

	for (int i = 0; i <= wcslen(b); i++)
		a[i] = b[i];
}

Student* laythongtin(wchar_t a[])
{
	int index = 0;
	int i;
	wchar_t **b = (wchar_t **)malloc(8 * sizeof(wchar_t));
	wchar_t *p;
	p = wcstok(a, L",");
	while (p != NULL)
	{
		b[index] = p;
		index++;
		p = wcstok(NULL, L","); //cat chuoi tu vi tri dung lai truoc do
	}

	Student* hs = (Student*)malloc(sizeof(Student));
	chuyen(b[0], hs->MSSV);
	chuyen(b[1], hs->Ten);
	chuyen(b[2], hs->Khoa);
	hs->KhoaTuyen = _wtoi(b[3]);
	chuyen(b[4], hs->Hinhanh);
	chuyen(b[5], hs->NgaySinh);
	chuyen(b[6], hs->Motabanthan);
	chuyen(b[7], hs->Sothich1);
	chuyen(b[8], hs->Sothich2);
	return hs;
}

void vietfile(wchar_t a[])
{
	Student *hs = laythongtin(a);
	wchar_t filename[60];
	wcscpy(filename, hs->MSSV);
	wcscat(filename, L".html");
	FILE* fo = _wfopen(filename, L"wt");
	fwprintf(fo, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
	fwprintf(fo, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
	fwprintf(fo, L"	<head>\n");
	fwprintf(fo, L"		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n");
	fwprintf(fo, L"		<link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
	//--%ls--
	fwprintf(fo, L"		<title>HCMUS - %ls</title>\n", hs->MSSV);
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
	fwprintf(fo, L"					<!-- Begin Thông tin cá nhân của thầy cô ----------------------------------------------------------------------------------------- -->\n");
	fwprintf(fo, L"					<div class=\"Personal_Location\"> \n");
	fwprintf(fo, L"						<img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
	//--%ls--
	fwprintf(fo, L"						<div class=\"Personal_FullName\">Phạm Minh Tuấn</div>\n");
	fwprintf(fo, L"						<div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"						<div class=\"Personal_Phone\">pmtuan@hcmus.edu.vn\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"						<br />\n");
	fwprintf(fo, L"					</div>\n");
	fwprintf(fo, L"					<!-- End Thông tin cá nhân của thầy cô ----------------------------------------------------------------------------------------- -->\n");
	fwprintf(fo, L"					<div class=\"Personal_HinhcanhanKhung\">\n");
	//--%ls--
	fwprintf(fo, L"						<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", hs->Hinhanh);
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
	fwprintf(fo, L"                              <li>Họ và tên: %ls </li>\n", hs->Ten);
	fwprintf(fo, L"								 <li>MSSV: %ls </li>\n", hs->MSSV);
	fwprintf(fo, L"								 <li>Sinh viên khoa %ls </li>\n", hs->Khoa);
	fwprintf(fo, L"								 <li>Ngày sinh: %ls </li>\n", hs->NgaySinh);
	fwprintf(fo, L"							 </ul>\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"                       <div class=\"InfoGroup\">Sở thích</div>\n");
	fwprintf(fo, L"                       <div>\n");
	fwprintf(fo, L"                            <ul class=\"TextInList\">\n");
	//--%ls--
	fwprintf(fo, L"                              <li>%ls</li>\n", hs->Sothich1);
	fwprintf(fo, L"								 <li>%ls</li>\n", hs->Sothich2);
	fwprintf(fo, L"							 </ul>\n");
	fwprintf(fo, L"						</div>\n");
	fwprintf(fo, L"						<div class=\"InfoGroup\">Mô tả</div>\n");
	fwprintf(fo, L"						<div class=\"Description\">\n");
	//--%ls--
	fwprintf(fo, L"                            %ls.\n", hs->Motabanthan);
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
	int n, i;
	FILE* fo = fopen("input.csv", "rt");
	wchar_t **a = TaoMang(fo, n);
	for (i = 0; i <= n; i++)
		vietfile(a[i]);
	if (i == n)
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\tThanh cong!!!");
	free(a);
}