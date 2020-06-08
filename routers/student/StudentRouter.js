const express = require('express');
const makeResponse = require('../../utils/makeResponse');

function StudentRouter() {
  const core = global.core;
  const router = express.Router();

  core.readStudents();
  
  router.get('/students', (req, res) => {
    const markAsNumber = Number(req.query.mark);
    const students = Number.isNaN(markAsNumber) ? core.getStudents() : core.getStudents(markAsNumber);

    res.json(makeResponse('ok', students)).send();
  });

  router.post('/students', (req, res) => {
    const { fio, groupId, index } = req.body;
    const groupIdAsNumber = Number(groupId);
    const indexAsNumber = Number(index);

    if (!fio || Number.isNaN(groupIdAsNumber) || Number.isNaN(indexAsNumber)) {
      res.json(makeResponse('error', { message: 'Invalid data' })).send();
    } else {
      const student = core.createStudent(fio, groupIdAsNumber, indexAsNumber);

      res.json(makeResponse('ok', student)).send();
    }
  });

  return router;
}

module.exports = StudentRouter;
