class File:
    def __init__(self, name, content):
        self.name = name
        self.content = content

    def get_name(self):
        return self.name

    def set_name(self, name):
        self.name = name

    def get_content(self):
        return self.content

    def set_content(self, content):
        self.content = content


class CloudStorage:
    def __init__(self):
        self.files = {}

    def upload_file(self, file_name, content):
        file = File(file_name, content)
        self.files[file_name] = file
        print(f"File uploaded successfully: {file_name}")

    def download_file(self, file_name):
        file = self.files.get(file_name)
        if file:
            print(f"File downloaded successfully: {file_name}")
            return file.get_content()
        else:
            print(f"File not found: {file_name}")
            return None

    def share_file(self, file_name, recipient):
        # Code to share file with recipient
        print(f"{file_name} shared with {recipient}")


if __name__ == "__main__":
    storage = CloudStorage()

    # Uploading a file
    storage.upload_file("document.txt", b"This is a test document.")

    # Downloading a file
    downloaded_content = storage.download_file("document.txt")
    if downloaded_content:
        print(f"Downloaded content: {downloaded_content.decode()}")

    # Sharing a file
    storage.share_file("document.txt", "user@example.com")
