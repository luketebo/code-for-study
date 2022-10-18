import { defineStore } from "pinia";
import { Names } from "./store-name";

type User = {
  name: string;
  age: number;
};

const Login = (): Promise<User> => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve({
        name: "Tebo",
        age: 20,
      });
    }, 2);
  });
};

export const useTestStore = defineStore(Names.TEST, {
  state: () => {
    return {
      // 初始化
      user: <User>{},
      name: ""
    };
  },
  // computed
  getters: {
    newName ():string {
        return '$-${this.name}'
    },
    getUserAge():Number {
        return this.user.age
    }
  },
  // methods
  actions: {
    async setUser() {
      const result = await Login();
      this.user = result;
    },
    setName(name: string) {
        this.name = name
    }
  },
});
