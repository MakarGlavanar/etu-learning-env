import React from "react";
import { TextField, Button, makeStyles, createStyles } from "@material-ui/core";
import { useStudents } from "../../useStudents";

interface AddStudentProps {
  addStudent: Function;
}

const useStyles = makeStyles(() =>
  createStyles({
    form: {
      flexDirection: "column",
    },
  })
);

export function AddStudent(props: AddStudentProps): JSX.Element {
  const classes = useStyles();
  const { addStudent } = props;

  const [fio, setFio] = React.useState("");
  const [groupId, setGroupId] = React.useState(0);
  const [index, setIndex] = React.useState(0);

  const handleSubmit = () => {
    addStudent({ fio, groupId, index });
  };

  return (
    <div className={classes.form}>
      <TextField
        label="ФИО"
        variant="outlined"
        onChange={(e: React.ChangeEvent<HTMLInputElement>) =>
          setFio(e.target.value)
        }
      />
      <br />
      <TextField
        label="Группа"
        variant="outlined"
        type="number"
        required
        onChange={(e: React.ChangeEvent<HTMLInputElement>) =>
          setGroupId(parseInt(e.target.value))
        }
      />
      <br />
      <TextField
        label="Номер в группе"
        variant="outlined"
        type="number"
        required
        onChange={(e: React.ChangeEvent<HTMLInputElement>) =>
          setIndex(parseInt(e.target.value))
        }
      />
      <br />
      <Button onClick={handleSubmit}>Создать</Button>
    </div>
  );
}
