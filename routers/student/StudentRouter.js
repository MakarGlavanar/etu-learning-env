const express = require('express');
const makeResponse = require('../../utils/makeResponse');

function StudentRouter() {
  const core = global.core;
  const router = express.Router();

  core.readStudents();
  
  router.get('/students', (req, res) => {
    const students = core.getStudents();

    res.json(makeResponse('ok', students)).send();
  });

  return router;
}

module.exports = StudentRouter;
