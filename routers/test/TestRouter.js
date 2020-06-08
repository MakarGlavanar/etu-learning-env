const express = require('express');
const makeResponse = require('../../utils/makeResponse');

function TestRouter() {
  const core = global.core;
  const router = express.Router();
  
  router.post('/test', (req, res) => {
    const { index, title } = req.body;

    const test = core.generateTest(Number(index) || 0, title);


    res.json(makeResponse('ok', test)).send();
  });

  return router;
}

module.exports = TestRouter;
