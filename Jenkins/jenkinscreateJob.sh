#!/bin/sh

if [ $# -ne 4 ]
  then
    echo "No arguments supplied"
    echo "1st argument : is your Jenkins user"
    echo "2nd argument : is your Jenkins password"
    echo "3th argument : is your job"
    echo "4th argument : is the jenkins type of your job [freestyle|pipeline]"
    exit 1
fi

USER=$1
APITOKEN=$2
JOB=$3
GROOVYSCRIPT=list-jobs.groovy
SERVER=127.0.0.1:10081

echo "Get Crumb from Jenkins-----------"
CRUMB=`curl "http://$USER:$APITOKEN@$SERVER/crumbIssuer/api/xml/?xpath=concat(//crumbRequestField,%22:%22,//crumb)"`
echo "Create a Jenkins Job-----------"
curl -v -X POST --data-binary "@Jenkins/""$4"".xml"  -H "Content-Type:application/xml" -H "$CRUMB" "http://$USER:Azerty123@$SERVER/createItem?name=$JOB"

