import React from "react";
import { Test } from "src/models/test";
import { Student } from "src/models/students";

export interface GetStudents {}

export interface CreateStudentBody {
  fio: string;
  groupId: number;
  index: number;
}

export interface CreateStudentResponse {
  status: string;
  data: Test;
}

export interface GetStudentsResponse {
  status: string;
  data: Student[];
}

export function useStudents() {
  const [students, setStudents] = React.useState([] as Student[]);

  async function createStudent(body: CreateStudentBody): Promise<void> {
    console.log(body);
    const response = await fetch("http://localhost:8080/api/students", {
      headers: {
        "Content-Type": "application/json",
      },
      method: "POST",
      body: JSON.stringify(body),
    });
    if (response.ok) {
      const result = (await response.json()) as CreateStudentResponse;
      if (result.status === "ok") {
        getStudents();
      }
    }
  }

  async function getStudents(): Promise<void> {
    const response = await fetch("http://localhost:8080/api/students", {
      headers: {
        "Content-Type": "application/json",
      },
      method: "GET",
    });
    if (response.ok) {
      const result = (await response.json()) as GetStudentsResponse;
      console.log(result.data);
      setStudents(result.data);
    }
  }

  return { students, createStudent, getStudents };
}
