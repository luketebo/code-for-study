import { createRouter, createWebHistory, RouteRecordRaw } from "vue-router";

const routes = [
  {
    path: "/",
    name: "home",
    component: () => import("../components/content/index.vue"),
  },
  {
    path: "/essay",
    name: "essay",
    component: () => import("../components/essay/index.vue"),
  },
  {
    path: "/code",
    name: "code",
    component: () => import("../components/knowledge/code.vue"),
  },
  {
    path: "/life",
    name: "life",
    component: () => import("../components/knowledge/life.vue"),
  },
  {
    path: "/odd",
    name: "odd",
    component: () => import("../components/knowledge/odd.vue"),
  },
];

const router = createRouter({
  history: createWebHistory(),
  routes,
});

export default router;
