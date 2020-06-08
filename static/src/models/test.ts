export interface Question {
  index: number;
  title: string;
  description: string;
  inputData: string;
  outputData: string;
  solution: string;
}

export interface Test {
  index: number;
  title: string;
  tasks: Question[];
}
