#
# Regular cron jobs for the wxdatefrom package.
#
0 4	* * *	root	[ -x /usr/bin/wxdatefrom_maintenance ] && /usr/bin/wxdatefrom_maintenance
