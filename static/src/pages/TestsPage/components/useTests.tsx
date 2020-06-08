import React from "react";
import { Test } from "src/models/test";

export interface CreateTestBody {
  index: number;
  title: string;
}

export interface CreateTestResponse {
  status: string;
  data: Test;
}

export function useTests() {
  const [test, setTest] = React.useState({} as Test);

  async function createTest(body: CreateTestBody): Promise<void> {
    const response = await fetch("http://localhost:8080/api/test", {
      headers: {
        "Content-Type": "application/json",
      },
      method: "POST",
      body: JSON.stringify(body),
    });
    if (response.ok) {
      const result = (await response.json()) as CreateTestResponse;
      setTest(result.data);
    }
  }

  return { test, createTest };
}
