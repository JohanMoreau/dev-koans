FROM golang:1.7.3
COPY app.go .
RUN go build -o app app.go

FROM scratch
COPY --from=0 /go/app .
CMD ["./app"]
