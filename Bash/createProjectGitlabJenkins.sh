#!/bin/bash

if [ $# -ne 5 ]
  then
    echo "No arguments supplied"
    echo "1st argument : is your Jenkins user"
    echo "2nd argument : is your Jenkins password"
    echo "3th argument : is your Gitlab token"
    echo "4th argument : is your job/project"
    echo "5th argument : is the jenkins type of your job [freestyle|pipeline]"
    exit 1
fi

./Gitlab/gitlabcreateProject.sh $3 $4
./Jenkins/jenkinscreateJob.sh $1 $2 $4 $5
