export enum RouteName {
  Students = "/students",
  Exams = "/exams",
  Tests = "/tests",
}

export interface RouteSchemaItem {
  href: RouteName;
  page: () => JSX.Element;
}
