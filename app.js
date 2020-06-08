require("dotenv").config();
const express = require("express");
const bodyParser = require("body-parser");
const core = require("bindings")("etu_le_core");

global.core = core;

const app = express();

app.use((req, res, next) => {
  res.setHeader("Access-Control-Allow-Origin", "*");
  res.setHeader("Access-Control-Allow-Methods", "GET, POST");
  res.setHeader(
    "Access-Control-Allow-Headers",
    "Origin, X-Requested-With, Content-Type, Accept, Authorization"
  );
  next();
});

app.use(bodyParser.json());

const testRouter = require("./routers/test/TestRouter");
const studentRouter = require("./routers/student/StudentRouter");

app.use("/api", testRouter());
app.use("/api", studentRouter());

const port = process.env.PORT;

app.listen(port, () => {
  console.log(`Server is listening on port ${port}...`);
});
