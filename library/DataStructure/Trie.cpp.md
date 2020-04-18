---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: DataStructure/Trie.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/Trie.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 21:47:05+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <int charsiz>
struct Node {
    char c;
    Node *to[charsiz];
    Node(char c) : c(c) {
        for (int i = 0; i < charsiz; i++) {
            to[i] = nullptr;
        }
    }
};
template <int charsiz>
struct Trie {
    Node<charsiz> *root;
    Trie() {
        root = new Node<charsiz>('?');
    }
    inline int index(const char &c) { return c - 'a'; }
    Node<charsiz> *insert(const string &s) {
        Node<charsiz> *now = root;
        for (int i = 0; i < s.length(); i++) {
            now = now->to[index(s[i])];
            if (now == nullptr) {
                now = new Node<charsiz>(s[i]);
            }
        }
        return now;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/Trie.cpp"
template <int charsiz>
struct Node {
    char c;
    Node *to[charsiz];
    Node(char c) : c(c) {
        for (int i = 0; i < charsiz; i++) {
            to[i] = nullptr;
        }
    }
};
template <int charsiz>
struct Trie {
    Node<charsiz> *root;
    Trie() {
        root = new Node<charsiz>('?');
    }
    inline int index(const char &c) { return c - 'a'; }
    Node<charsiz> *insert(const string &s) {
        Node<charsiz> *now = root;
        for (int i = 0; i < s.length(); i++) {
            now = now->to[index(s[i])];
            if (now == nullptr) {
                now = new Node<charsiz>(s[i]);
            }
        }
        return now;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
