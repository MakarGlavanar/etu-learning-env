import React from "react";
import { Paper, Button, TextField } from "@material-ui/core";
import { CreateTestBody } from "../useTests";

interface TestGeneratorProps {
  createTest: (body: CreateTestBody) => Promise<void>;
}

export function TestGenerator(props: TestGeneratorProps): JSX.Element {
  const { createTest } = props;
  const [index, setIndex] = React.useState(0);
  const [title, setTitle] = React.useState("");

  const handleClick = () => {
    createTest({ title, index });
  };

  return (
    <>
      <TextField
        type="number"
        variant="outlined"
        label="Номер варианта"
        onChange={(e: React.ChangeEvent<HTMLInputElement>) =>
          setIndex(parseInt(e.target.value, 10))
        }
      ></TextField>
      <br />
      <br />
      <TextField
        variant="outlined"
        label="Название теста"
        onChange={(e: React.ChangeEvent<HTMLInputElement>) =>
          setTitle(e.target.value)
        }
      ></TextField>
      <br />
      <br />
      <Button variant="outlined" onClick={handleClick}>
        создать тест
      </Button>
    </>
  );
}
