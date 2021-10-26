# !/bin/bash
while true; do
	minishell_pid=$(pgrep minishell)
	if [ -n "$minishell_pid" ]
	then
		leaks_result=$( leaks -q --list minishell ) 
		lsof_result=$( lsof -p $minishell_pid )
		processes=$(ps)
		echo "                                 \033[35;1mLEAKS CHECK"
		echo "\033[32;1m$leaks_result"
		echo "                                 \033[35;1mFD CHECK"
		echo "\033[32;1m$lsof_result\033[0m"
		echo "                                 \033[35;1mPROCESSES"
		echo "\033[32;1m$processes\033[0m"
	fi
	sleep 3
	clear
done
