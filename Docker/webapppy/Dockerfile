# our base image
FROM alpine:latest
# Install python and pip
RUN apk add --update py2-pip
# install Python modules needed by the Python app
COPY src/requirements.txt /usr/src/app/
RUN pip install --no-cache-dir -r /usr/src/app/requirements.txt
# copy files required for the app to run
COPY src/app.py /usr/src/app/
COPY src/templates/index.html /usr/src/app/templates/
# tell the port number the container should expose
EXPOSE 5000
# run the application
CMD ["python", "/usr/src/app/app.py"]
