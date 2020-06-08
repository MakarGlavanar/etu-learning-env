import React from "react";
import { Typography } from "@material-ui/core";
import { TestGenerator } from "./components/TestGenerator/TestGenerator";
import { TestViewer } from "./components/TestViewer/TestViewer";
import { useTests } from "./components/useTests";

export const TestsPage: React.FC = () => {
  const { test, createTest } = useTests();

  return (
    <>
      <Typography variant="h3">Сгенерировать тест</Typography>
      <TestGenerator createTest={createTest} />
      <TestViewer test={test} />
    </>
  );
};
