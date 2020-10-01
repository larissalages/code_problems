public class Trie{
    static final int SIZE_OF_ALPHABET = 26;
    static class TrieNode{
        TrieNode[] children = new TrieNode[SIZE_OF_ALPHABET];
        TrieNode(){
            isEndOfWord = false;
            for (int i = 0; i < SIZE_OF_ALPHABET; i++){
                children[i] = null;
            }
        }
    }
    static TrieNode root;

    static void insert (String key){s
        int index;
        int level;
        TrieNode currentNode = root;
        for (level = 0; level < key.length(); level++){
            index = key.charAt(level) - 'a';
            if (currentNode[index] == null){
                currentNode[index] = new TrieNode();
            }
            currentNode = currentNode.children[index];
        }
        currentNode.isEndOfWord = true;
    }

    static boolean search (String searched_string){
        TrieNode currentNode = root;
        for (int level = 0; level < searched_string.length(); level++){
            int index = searched_string.charAt(level) - 'a';
            if (currentNode.children[index] != null){
                currentNode = currentNode.children[index]
            } else {
                return false;
            }
        }
        return (currentNode != null && currentNode.isEndOfWord == true)
    }
}