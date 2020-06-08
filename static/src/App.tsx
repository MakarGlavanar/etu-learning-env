import React from "react";
import { ThemeProvider } from "@material-ui/core";
import theme from "./theme";
import { BrowserRouter, Switch, Route } from "react-router-dom";
import "./App.css";
import { Navbar } from "./common/Navbar/Navbar";
import { Routing } from "./common/Routing/Routing";
import { StudentsPage } from "./pages/StudentsPage/StudentsPage";
import { ExamPage } from "./pages/ExamPage/ExamPage";
import { TestsPage } from "./pages/TestsPage/TestsPage";
import { RouteName, RouteSchemaItem } from "./models/route";
import { Link } from "./models/link";

const navbarLinks = [
  {
    name: "Создать задачи",
    href: RouteName.Tests,
  },
  {
    name: "Провести экзамен",
    href: RouteName.Exams,
  },
  {
    name: "Список студентов",
    href: RouteName.Students,
  },
] as Link[];

function App() {
  return (
    <ThemeProvider theme={theme}>
      <div className="App">
        <BrowserRouter>
          <Navbar links={navbarLinks} />
          <Switch>
            <Route path="/tests">
              <TestsPage />
            </Route>
            <Route path="/students">
              <StudentsPage />
            </Route>
          </Switch>
        </BrowserRouter>
      </div>
    </ThemeProvider>
  );
}

export default App;
