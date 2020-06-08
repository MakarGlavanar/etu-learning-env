require('dotenv').config();
const express = require('express');
const bodyParser = require('body-parser');
const core = require('bindings')('etu_le_core');

global.core = core;

const app = express();
app.use(bodyParser.json());

const testRouter = require('./routers/test/TestRouter');

app.use("/", testRouter());

const port = process.env.PORT;

app.listen(port, () => {
  console.log(`Server is listening on port ${port}...`);
});
