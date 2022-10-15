<template>
  <div class="wraps">
    <header class="header">
      <div>left</div>
      <div>中间</div>
      <div>right</div>
    </header>

    <main class="main">
      <div class="main-items" v-for="item in 100">
        <div class="main-port">头像</div>
        <div class="main-desc">
          <div>小满{{ item }}</div>
          <div>你妈妈喊你回家穿丝袜啦</div>
        </div>
      </div>
    </main>


    <footer class="footer">
      <div class="footer-items" v-for="item in footer">
        <div>{{ item.icon }}</div>
        <div>{{ item.text }}</div>
      </div>
    </footer>
  </div>

</template>

<script setup lang='ts'>
import {reactive} from 'vue';

type Footer<T> = {
  icon: T,
  text: T
}

const footer = reactive<Footer<string>[]>([
  {
    icon: "1",
    text: "首页"
  },
  {
    icon: "2",
    text: "商品"
  },
  {
    icon: "3",
    text: "信息"
  },
  {
    icon: "4",
    text: "我的"
  }
])
</script>

<style lang="less">


html,
body,
#app {
  height: 100%;
  overflow: hidden;
  font-size: 14px;
}

.wraps {
  height: inherit;
  overflow: hidden;
  display: flex;
  flex-direction: column;
}

.header {
  background-color: pink;
  display: flex;
  height: 30px;
  align-items: center;
  justify-content: space-around;

  div:nth-child(1) {
    width: 40px;
  }

  div:nth-child(2) {
    text-align: center;
  }

  div:nth-child(3) {
    width: 40px;
    text-align: right;
  }
}

.main {
  flex: 1;
  overflow: auto;

  &-items {
    display: flex;
    border-bottom: 1px solid #ccc;
    box-sizing: border-box;
    padding: 5px;
  }

  &-port {
    background: black;
    width: 30px;
    height: 30px;
    border-radius: 200px;
  }

  &-desc {
    margin-left: 10px;

    div:last-child {
      font-size: 10px;
      color: #333;
      margin-top: 5px;
    }
  }
}

.footer {

  border-top: 1px solid #ccc;
  display: grid;
  grid-template-columns: 1fr 1fr 1fr 1fr;

  &-items {
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    padding: 5px;
  }
}
</style>