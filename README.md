## 🗂️ Inverted Search Project

### Project Overview

This project implements an **Inverted Search** system using **hashing** and indexing techniques to enable fast text searches across multiple documents.

An **inverted index** is a data structure that maps each unique word to the list of documents where it appears. This allows quick retrieval of files containing the search terms without scanning all documents each time.

### How It Works

- **Indexing:**  
  Parse input text files to extract words, store them in a hash table or sorted linked list along with their corresponding document information, and save this index to a database file.

- **Searching:**  
  Parse query words and search the index to quickly identify and return documents containing those words.

### Key Concepts

- Use of **hashing** or **linked lists** for efficient word storage and retrieval.  
- File parsing and tokenization for word extraction.  
- Persistent storage of the inverted index for faster subsequent searches.

### Use Cases

- Basic search functionality for document collections.  
- Educational project demonstrating indexing and hashing.  
- Foundation for building text retrieval systems.

---
