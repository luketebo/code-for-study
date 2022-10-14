<template>

  <div></div>

</template>

<script setup lang='ts'>
import { ref, reactive, nextTick } from 'vue'
const message = ref<string>('Luke')
const div = ref<HTMLElement>()
const current = ref<number>(0)

const change = async () => {
  message.value = "LukeTebo"
  await nextTick()

  console.log(div.value?.innerText);
  for (let i = 0; i < 100; i++) {
    current.value = i
  }

  // 面试题
  for (var i = 0; i < 5; i++) {
    setTimeout(() => {
      console.log(i);
      
    })
  }

}


</script>
<style scoped lang='less'>

</style>