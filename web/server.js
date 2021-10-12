const express = require("express");
const bodyParser = require("body-parser");

const app = express();
app.use(bodyParser.urlencoded({extended: true}));
app.use(express.static("public"));

const port = 4000;

app.get("/", (req, res) => {
    res.sendFile(__dirname + "/public/html/index.html");
});

app.listen(port, () => {
    console.log("server opened at port : " + port);
});
