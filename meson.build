project('wxdatefrom', 'cpp', version: '0.2')
subdir('po')
wx_dep = dependency('wxwidgets', version : '>=3.0.0', required : true)
executable('wxdatefrom', ['wxDateFromApp.cpp','wxDateFromMain.cpp'], dependencies : [wx_dep], install: true)

install_data('wxdatefrom.jpg',
             install_dir : '/usr/share/icons')
install_data('wxDateFrom.desktop',
             install_dir : '/usr/share/applications')
