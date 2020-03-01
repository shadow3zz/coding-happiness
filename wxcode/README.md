<!--
 * @Descripttion: 
 * @version: WSL:Ubuntu-16.04
 * @Author: shadow3zz-zhouchenghao@whut.edu.cn
 * @Date: 2020-02-25 23:21:31
 * @LastEditors: shadow3zz
 * @LastEditTime: 2020-02-25 23:21:32
 -->

# `wx/log.h`

## 初始化

```c++
bool OCPNPlatform::InitializeLogFile( void )
{
    //      Establish Log File location
    mlog_file = GetPrivateDataDir();
    appendOSDirSlash( &mlog_file );

    // create the opencpn "home" directory if we need to
    wxFileName wxHomeFiledir( GetHomeDir() );
    if( true != wxHomeFiledir.DirExists( wxHomeFiledir.GetPath() ) )
        if( !wxHomeFiledir.Mkdir( wxHomeFiledir.GetPath() ) ) {
            wxASSERT_MSG(false,_T("Cannot create wxTemplate home directory"));
            return false;
    }

        // create the opencpn "log" directory if we need to
    wxFileName wxLogFiledir( mlog_file );
    if( true != wxLogFiledir.DirExists( wxLogFiledir.GetPath() ) ) {
        if( !wxLogFiledir.Mkdir( wxLogFiledir.GetPath() ) ) {
            wxASSERT_MSG(false,_T("Cannot create wxTemplate log directory"));
            return false;
        }
    }

    mlog_file.Append( _T("wxTemplate.log") );
    wxString logit = mlog_file;
        //  Constrain the size of the log file
    if( ::wxFileExists( mlog_file ) ) {
            if( wxFileName::GetSize( mlog_file ) > 1000000 ) {
                wxString oldlog = mlog_file;
                oldlog.Append( _T(".log") );
                //  Defer the showing of this messagebox until the system locale is established.
                large_log_message = ( _T("Old log will be moved to wxTemplate.log.log") );
                ::wxRenameFile( mlog_file, oldlog );
            }
    }

    flog = fopen( mlog_file.mb_str(), "a" );
    g_logger = new wxLogStderr( flog );

#if defined(__WXGTK__) || defined(__WXOSX__)
    g_logger->SetTimestamp(_T("%H:%M:%S %Z"));
#endif

    m_Oldlogger = wxLog::SetActiveTarget( g_logger );

    return true;
}
```

# `wx/filename.h`

## 路径获取

```c++
wxStandardPaths& std_path = GetStdPaths();
std_path.GetUserDataDir();
std_path.GetDataDir();
std_path.GetExecutablePath();
std_path.GetUserConfigDir();
```

# `wx/string.h`

## `wxString& Trim(bool bFromRight = true)`

Removes white-space (space, tabs, form feed, newline and carriage return) from the left or from the right end of the string (right is default).

从字符串的左端或右端删除空白(空格、制表符、表单提要、换行和回车)(右端是默认值)。

## `wxString& Prepend(const wxString& str)` and `wxString& Append(const wxString& s)`

从字符串的左端或右端添加字符串。

# `platinfo.h`

# 宏定义

## [wxArray< T > Class Template Reference](https://docs.wxwidgets.org/3.0.2/classwx_array_3_01_t_01_4.html)

### `WX_DEFINE_ARRAY_PTR(double *, MyArrayOfDoublePointers)`
