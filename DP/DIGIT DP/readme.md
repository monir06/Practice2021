# To-dos
1. https://toph.co/c/operation-coding (problem b) solution: https://pastebin.ubuntu.com/p/7KKqV4k3Gf/
    Given two integers L and R. Let’s define XR=L⊕(L+1)⊕(L+2)⊕(L+3)⊕...⊕R (⊕ is bitwise XOR) Is there any integer M such that, (XR⊕M) < XR where L≤M≤R?

    Constraint: 1≤ L ≤ R ≤ 10^16

    Limits: 1s, 512 MB

    How to find M ?
    ডিজিট ডিপির একটা সলিউশন সম্ভব।
    মূলত গ্রিডি ওয়ে.
    1 থেকে n পর্যন্ত xor বের করার একটা উপায় আছে (নিচে এটাচ করে দিয়েছি)। এটা জানলে আমরা L থেকে R পর্যন্ত xor বের করে ফেলতে পারবো।
    সেটা যদি পারি, তাহলে আমরা যদি ওই xor ভ্যালুর কোন একটা বিট অফ করে দিতে পারি, তাহলেই আমাদের আন্সার আসা সম্ভব। এখন বিট টা কিভাবে অফ করতে পারি? সেটা হলো, আমরা i তম বিট অফ করার জন্য 2^i থেকে 2^(i+1) - 1 পর্যন্ত যেকোন নাম্বার ব্যবহার করতে পারবো। (কেন পারবো সেটা আপনাকে চিন্তা করতে দেওয়া হলো) এখন এই রেঞ্জ টা যদি L থেকে R এর মধ্যে থাকে তাহলেই আমাদের আন্সার আমরা পেয়ে গেলাম।
    i th বিট অফ করতে সময় যদি অন্য কোন বিট অন হয়ে যায় যার ফলে M > R হয়ে যায় ? 
    ধরি, ith বিট অফ করার সময় যে রেঞ্জ টা আমরা সিলেক্ট করবো সেটার ম্যাক্স যদি L এর বড় হয় আর মিনিমাম R এর ছোট হয়, তাহলেই আমাদের আন্সার এক্সিস্ট করে।
    xor from 1 to n =>
    ll cxr(ll n){
      ll md = n % 4;
      if (md == 0) return n;
      else if (md == 1) return 1;
      else if (md == 2) return n + 1;
      else return 0;
    }
  2. 
    
