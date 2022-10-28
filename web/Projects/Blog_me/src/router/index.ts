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
  {
    path: "/system",
    name: "system",
    component: () => import("../components/tools/system.vue"),
  },
  {
    path: "/star",
    name: "star",
    component: () => import("../components/tools/star.vue"),
  },
  {
    path: "/operate",
    name: "operate",
    component: () => import("../components/tools/operate.vue"),
  },
  {
    path: "/paper",
    name: "paper",
    component: () => import("../components/paper/index.vue"),
  },


];

const router = createRouter({
  history: createWebHistory(),
  routes,
});

export default router;
