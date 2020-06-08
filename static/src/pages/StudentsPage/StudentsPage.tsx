import React from "react";
import { Typography } from "@material-ui/core";
import { StudentsList } from "./components/StudentsList/StudentsList";
import { useStudents } from "./useStudents";
import { AddStudent } from "./components/AddStudent/AddStudent";

export function StudentsPage(): JSX.Element {
  const { students, createStudent, getStudents } = useStudents();

  React.useEffect(() => {
    getStudents();
  }, []);

  return (
    <>
      <Typography variant="h4">Список студентов</Typography>
      <AddStudent addStudent={createStudent} />
      <StudentsList students={students} />
    </>
  );
}
