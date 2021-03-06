#ifndef _TL_LOGGER_H
#define _TL_LOGGER_H

#include <stdio.h>
#include <string>

#include "TLAttributes.h"

namespace TLib::Logger
{
   inline void Print(const wchar_t* v)       { ::wprintf(v); }
   inline void Print(const char* v)          { ::printf(v); }
   inline void Print(const unsigned char* v) { ::printf((const char*)v); }
   inline void Print(char v)                 { ::printf("%c", v); }
   inline void Print(unsigned char v)        { ::printf("%c", v); }
   inline void Print(int v)                  { ::printf("%i", v); }
   inline void Print(unsigned v)             { ::printf("%u", v); }
   inline void Print(float v)                { ::printf("%f", v); }
   inline void Print(const std::string& v)   { ::printf(v.data()); }
   template<size_t S>
   inline void Print(const char(&msg)[S])
   {
      ::printf(msg);
   }
   template<typename T>
   inline void Print(const T& t)
   {
      ::printf(::TLib::ToString(t).data());
   }
   template<typename T, typename ... R>
   inline void Print(const T& t, const R& ... r)
   {
      Print(t);
      Print(r...);
   }
#if TL_OS_IS_WINDOWS
   namespace Color
   {
      struct Type { unsigned val; };
      constexpr Type Black{0};
      constexpr Type DarkBlue{1};
      constexpr Type DarkGreen{2};
      constexpr Type DarkCyan{3};
      constexpr Type DarkRed{4};
      constexpr Type DarkMagenta{5};
      constexpr Type DarkYellow{6};
      constexpr Type Gray{7};
      constexpr Type DarkGray{8};
      constexpr Type Blue{9};
      constexpr Type Green{10};
      constexpr Type Cyan{11};
      constexpr Type Red{12};
      constexpr Type Magenta{13};
      constexpr Type Yellow{14};
      constexpr Type White{15};
   }
   inline void Print(Color::Type t) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), t.val); }
#endif
   struct WinMsg
   {
      UINT msg;
      WPARAM wp;
      LPARAM lp;
      template<class T>
      friend std::basic_ostream<T>& operator<<(std::basic_ostream<T>& os, WinMsg msg)
      {
         switch (msg.msg)
         {
#define REGMSG(m) case m:os<<#m;break
            REGMSG(WM_CREATE);
            REGMSG(WM_DESTROY);
            REGMSG(WM_MOVE);
            REGMSG(WM_SIZE);
            REGMSG(WM_ACTIVATE);
            REGMSG(WM_SETFOCUS);
            REGMSG(WM_KILLFOCUS);
            REGMSG(WM_ENABLE);
            REGMSG(WM_SETREDRAW);
            REGMSG(WM_SETTEXT);
            REGMSG(WM_GETTEXT);
            REGMSG(WM_GETTEXTLENGTH);
            REGMSG(WM_PAINT);
            REGMSG(WM_CLOSE);
            REGMSG(WM_QUERYENDSESSION);
            REGMSG(WM_QUIT);
            REGMSG(WM_QUERYOPEN);
            REGMSG(WM_ERASEBKGND);
            REGMSG(WM_SYSCOLORCHANGE);
            REGMSG(WM_ENDSESSION);
            REGMSG(WM_SHOWWINDOW);
            REGMSG(WM_CTLCOLORMSGBOX);
            REGMSG(WM_CTLCOLOREDIT);
            REGMSG(WM_CTLCOLORLISTBOX);
            REGMSG(WM_CTLCOLORBTN);
            REGMSG(WM_CTLCOLORDLG);
            REGMSG(WM_CTLCOLORSCROLLBAR);
            REGMSG(WM_CTLCOLORSTATIC);
            REGMSG(WM_WININICHANGE);
            REGMSG(WM_DEVMODECHANGE);
            REGMSG(WM_ACTIVATEAPP);
            REGMSG(WM_FONTCHANGE);
            REGMSG(WM_TIMECHANGE);
            REGMSG(WM_CANCELMODE);
            REGMSG(WM_SETCURSOR);
            REGMSG(WM_MOUSEACTIVATE);
            REGMSG(WM_CHILDACTIVATE);
            REGMSG(WM_QUEUESYNC);
            REGMSG(WM_GETMINMAXINFO);
            REGMSG(WM_ICONERASEBKGND);
            REGMSG(WM_NEXTDLGCTL);
            REGMSG(WM_SPOOLERSTATUS);
            REGMSG(WM_DRAWITEM);
            REGMSG(WM_MEASUREITEM);
            REGMSG(WM_DELETEITEM);
            REGMSG(WM_VKEYTOITEM);
            REGMSG(WM_CHARTOITEM);
            REGMSG(WM_SETFONT);
            REGMSG(WM_GETFONT);
            REGMSG(WM_QUERYDRAGICON);
            REGMSG(WM_COMPAREITEM);
            REGMSG(WM_COMPACTING);
            REGMSG(WM_NCCREATE);
            REGMSG(WM_NCDESTROY);
            REGMSG(WM_NCCALCSIZE);
            REGMSG(WM_NCHITTEST);
            REGMSG(WM_NCPAINT);
            REGMSG(WM_NCACTIVATE);
            REGMSG(WM_GETDLGCODE);
            REGMSG(WM_NCMOUSEMOVE);
            REGMSG(WM_NCLBUTTONDOWN);
            REGMSG(WM_NCLBUTTONUP);
            REGMSG(WM_NCLBUTTONDBLCLK);
            REGMSG(WM_NCRBUTTONDOWN);
            REGMSG(WM_NCRBUTTONUP);
            REGMSG(WM_NCRBUTTONDBLCLK);
            REGMSG(WM_NCMBUTTONDOWN);
            REGMSG(WM_NCMBUTTONUP);
            REGMSG(WM_NCMBUTTONDBLCLK);
            REGMSG(WM_KEYDOWN);
            REGMSG(WM_KEYUP);
            REGMSG(WM_CHAR);
            REGMSG(WM_DEADCHAR);
            REGMSG(WM_SYSKEYDOWN);
            REGMSG(WM_SYSKEYUP);
            REGMSG(WM_SYSCHAR);
            REGMSG(WM_SYSDEADCHAR);
            REGMSG(WM_KEYLAST);
            REGMSG(WM_INITDIALOG);
            REGMSG(WM_COMMAND);
            REGMSG(WM_SYSCOMMAND);
            REGMSG(WM_TIMER);
            REGMSG(WM_HSCROLL);
            REGMSG(WM_VSCROLL);
            REGMSG(WM_INITMENU);
            REGMSG(WM_INITMENUPOPUP);
            REGMSG(WM_MENUSELECT);
            REGMSG(WM_MENUCHAR);
            REGMSG(WM_ENTERIDLE);
            REGMSG(WM_MOUSEWHEEL);
            REGMSG(WM_MOUSEMOVE);
            REGMSG(WM_LBUTTONDOWN);
            REGMSG(WM_LBUTTONUP);
            REGMSG(WM_LBUTTONDBLCLK);
            REGMSG(WM_RBUTTONDOWN);
            REGMSG(WM_RBUTTONUP);
            REGMSG(WM_RBUTTONDBLCLK);
            REGMSG(WM_MBUTTONDOWN);
            REGMSG(WM_MBUTTONUP);
            REGMSG(WM_MBUTTONDBLCLK);
            REGMSG(WM_PARENTNOTIFY);
            REGMSG(WM_MDICREATE);
            REGMSG(WM_MDIDESTROY);
            REGMSG(WM_MDIACTIVATE);
            REGMSG(WM_MDIRESTORE);
            REGMSG(WM_MDINEXT);
            REGMSG(WM_MDIMAXIMIZE);
            REGMSG(WM_MDITILE);
            REGMSG(WM_MDICASCADE);
            REGMSG(WM_MDIICONARRANGE);
            REGMSG(WM_MDIGETACTIVE);
            REGMSG(WM_MDISETMENU);
            REGMSG(WM_CUT);
            REGMSG(WM_COPYDATA);
            REGMSG(WM_COPY);
            REGMSG(WM_PASTE);
            REGMSG(WM_CLEAR);
            REGMSG(WM_UNDO);
            REGMSG(WM_RENDERFORMAT);
            REGMSG(WM_RENDERALLFORMATS);
            REGMSG(WM_DESTROYCLIPBOARD);
            REGMSG(WM_DRAWCLIPBOARD);
            REGMSG(WM_PAINTCLIPBOARD);
            REGMSG(WM_VSCROLLCLIPBOARD);
            REGMSG(WM_SIZECLIPBOARD);
            REGMSG(WM_ASKCBFORMATNAME);
            REGMSG(WM_CHANGECBCHAIN);
            REGMSG(WM_HSCROLLCLIPBOARD);
            REGMSG(WM_QUERYNEWPALETTE);
            REGMSG(WM_PALETTEISCHANGING);
            REGMSG(WM_PALETTECHANGED);
            REGMSG(WM_DROPFILES);
            REGMSG(WM_POWER);
            REGMSG(WM_WINDOWPOSCHANGED);
            REGMSG(WM_WINDOWPOSCHANGING);
            REGMSG(WM_HELP);
            REGMSG(WM_NOTIFY);
            REGMSG(WM_CONTEXTMENU);
            REGMSG(WM_TCARD);
            REGMSG(WM_MDIREFRESHMENU);
            REGMSG(WM_MOVING);
            REGMSG(WM_STYLECHANGED);
            REGMSG(WM_STYLECHANGING);
            REGMSG(WM_SIZING);
            REGMSG(WM_SETHOTKEY);
            REGMSG(WM_PRINT);
            REGMSG(WM_PRINTCLIENT);
            REGMSG(WM_POWERBROADCAST);
            REGMSG(WM_HOTKEY);
            REGMSG(WM_GETICON);
            REGMSG(WM_EXITMENULOOP);
            REGMSG(WM_ENTERMENULOOP);
            REGMSG(WM_DISPLAYCHANGE);
            REGMSG(WM_SETICON);
            REGMSG(WM_CAPTURECHANGED);
            REGMSG(WM_DEVICECHANGE);
            REGMSG(WM_IME_SETCONTEXT);
            REGMSG(WM_IME_NOTIFY);
            REGMSG(WM_NCMOUSELEAVE);
            REGMSG(WM_EXITSIZEMOVE);
            REGMSG(WM_DWMNCRENDERINGCHANGED);
            REGMSG(WM_ENTERSIZEMOVE);
#undef REGMSG
         default:os << msg.msg; break;
         }
         return os << ". WPARAM: " << std::hex << msg.wp << ". LPARAM: " << msg.lp << std::dec << '.';
      }
   };
   struct WinSysCmd
   {
      WPARAM wp;
      template<class T>
      friend std::basic_ostream<T>& operator<<(std::basic_ostream<T>& os, WinSysCmd msg)
      {
         switch (msg.wp)
         {
#define REGMSG(m) case m:os<<#m;break
            REGMSG(SC_SIZE);
            REGMSG(SC_MOVE);
            REGMSG(SC_MINIMIZE);
            REGMSG(SC_MAXIMIZE);
            REGMSG(SC_NEXTWINDOW);
            REGMSG(SC_PREVWINDOW);
            REGMSG(SC_CLOSE);
            REGMSG(SC_VSCROLL);
            REGMSG(SC_HSCROLL);
            REGMSG(SC_MOUSEMENU);
            REGMSG(SC_KEYMENU);
            REGMSG(SC_ARRANGE);
            REGMSG(SC_RESTORE);
            REGMSG(SC_TASKLIST);
            REGMSG(SC_SCREENSAVE);
            REGMSG(SC_HOTKEY);
            REGMSG(SC_DEFAULT);
            REGMSG(SC_MONITORPOWER);
            REGMSG(SC_CONTEXTHELP);
            REGMSG(SC_SEPARATOR);
#undef REGMSG
         default:os << msg.wp; break;
         }
         return os;
      }
   };
   struct HResult
   {
      HResult(long value) : value(value)
      {
      }
      long value;
      template<class T>
      friend std::basic_ostream<T>& operator<<(std::basic_ostream<T>& os, HResult hr)
      {
         return os << hr.value;
      }
      std::string GetMessageString()
      {
         char* msg;
         std::string str;
         DWORD len = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER |
                                    FORMAT_MESSAGE_FROM_SYSTEM |
                                    FORMAT_MESSAGE_IGNORE_INSERTS,
                                    nullptr,
                                    value,
                                    MAKELANGID(LANG_NEUTRAL,
                                               SUBLANG_DEFAULT),
                                               (char*)& msg,
                                    0,
                                    nullptr);
         if (len != 0)
         {
            msg[len - 1] = 0; // \n
            msg[len - 2] = 0; // \r
            str = msg;
            LocalFree(msg);
         }
         return str;
      }
   };
}

#endif