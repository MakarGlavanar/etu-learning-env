import React from "react";
import { Switch, Route } from "react-router-dom";
import { RouteSchemaItem } from "../../models/route";

interface RoutingProps {
  routeSchema: RouteSchemaItem[];
}

export function Routing(props: RoutingProps): JSX.Element {
  const { routeSchema } = props;

  return (
    <Switch>
      {routeSchema.map((route) => (
        <Route path={route.href}>{route.page}</Route>
      ))}
    </Switch>
  );
}
