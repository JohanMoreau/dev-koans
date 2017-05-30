#!/bin/sh

if [ $# -ne 2 ]
  then
    echo "No arguments supplied"
    echo "First argument is your GitLab token"
    echo "Second argument is your new project"
    exit 1
fi

echo "Create a GitLab project -----------"
curl --header "PRIVATE-TOKEN:$1" -X POST "http://127.0.0.1:10080/api/v3/projects?name=$2"
echo "Get ID GitLab project -----------"
IDS=`curl --header "PRIVATE-TOKEN:$1" GET "http://127.0.0.1:10080/api/v4/projects?search=$2&simple=true"`
ID=`echo "$IDS"|tr "," '\n'|sed -e "s/\"//g"|grep "id:"|sed -e 's/\[{id://'`
echo "Add hook to Jenkins -----------"
curl --header "PRIVATE-TOKEN:$1" -X POST "http://127.0.0.1:10080/api/v4/projects/$ID/hooks?url=http://jenkins:8080/project/$2&push_events=true&token=d738cdacfb22fcce95ae5cfa7c065972"
