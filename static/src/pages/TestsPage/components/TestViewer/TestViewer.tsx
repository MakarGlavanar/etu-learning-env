import React from "react";
import {
  Typography,
  ExpansionPanel,
  ExpansionPanelSummary,
  ExpansionPanelDetails,
  makeStyles,
  createStyles,
} from "@material-ui/core";
import { Test } from "src/models/test";
import ExpandMoreIcon from "@material-ui/icons/ExpandMore";

interface TestProps {
  test: Test;
}

const useStyles = makeStyles(() =>
  createStyles({
    root: {
      position: "relative",
    },
    expansionPanel: {
      width: 400,
      margin: "4px auto !important",
    },
    details: {
      flexDirection: "column",
    },
  })
);

export function TestViewer(props: TestProps): JSX.Element {
  const { test } = props;
  const classes = useStyles();

  console.log(test);
  return (
    <div className={classes.root}>
      {test.title && (
        <>
          <Typography variant="h4">
            {test.title} (вариант {test.index})
          </Typography>
          {test.tasks &&
            test.tasks.map((task) => (
              <ExpansionPanel
                className={classes.expansionPanel}
                key={task.index}
              >
                <ExpansionPanelSummary expandIcon={<ExpandMoreIcon />}>
                  Вопрос {task.index + 1}
                </ExpansionPanelSummary>
                <ExpansionPanelDetails className={classes.details}>
                  <Typography variant="h6">{task.title}</Typography>
                  <Typography>Условие: {task.description}</Typography>
                  <Typography>Входные данные: {task.inputData}</Typography>
                  <Typography>Выходные данные: {task.outputData}</Typography>
                  <Typography>Ответ: {task.solution}</Typography>
                </ExpansionPanelDetails>
              </ExpansionPanel>
            ))}
        </>
      )}
    </div>
  );
}
