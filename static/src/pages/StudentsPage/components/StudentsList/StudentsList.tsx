import React from "react";
import {
  List,
  ListItem,
  ListItemText,
  Typography,
  Divider,
} from "@material-ui/core";
import { Student } from "src/models/students";

interface StudentsListProps {
  students: Student[];
}

interface StudentInfoProps {
  student: Student;
}

function StudentInfo(props: StudentInfoProps): JSX.Element {
  const { fio, groupId, index } = props.student;

  return (
    <>
      <Divider />
      <ListItem alignItems="flex-start">
        <ListItemText
          primary={fio}
          secondary={
            <Typography color="textPrimary" variant="body2">
              {groupId}, {index}
            </Typography>
          }
        />
      </ListItem>
      <Divider />
    </>
  );
}

export function StudentsList(props: StudentsListProps): JSX.Element {
  const { students } = props;

  return (
    <List>
      {students.map((student) => (
        <StudentInfo key={student.id} student={student} />
      ))}
    </List>
  );
}
