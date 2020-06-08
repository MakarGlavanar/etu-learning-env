import React from "react";
import {
  AppBar,
  Toolbar,
  Typography,
  Button,
  makeStyles,
  createStyles,
  useTheme,
  Theme,
} from "@material-ui/core";
import { Link as RouterLink } from "react-router-dom";

interface NavbarLink {
  name: string;
  href: string;
}

interface NavbarProps {
  links: NavbarLink[];
}

const useStyles = makeStyles((theme: Theme) =>
  createStyles({
    root: {
      flexGrow: 1,
    },
    title: {
      flexGrow: 1,
    },
    navbarLink: {
      marginRight: theme.spacing(2),
    },
  })
);

export function Navbar(props: NavbarProps): JSX.Element {
  const { links } = props;
  const classes = useStyles();

  return (
    <div className={classes.root}>
      <AppBar position="static">
        <Toolbar>
          <Typography variant="h6" align="left" className={classes.title}>
            «СПбГТУ ЛЭТИ» Помощник Преподавателя
          </Typography>
          {links.map((link) => (
            <Button
              variant="outlined"
              color="inherit"
              key={link.href}
              component={RouterLink}
              to={link.href}
              className={classes.navbarLink}
            >
              {link.name}
            </Button>
          ))}
        </Toolbar>
      </AppBar>
    </div>
  );
}
