class VideoConference:
    def __init__(self, host):
        self.host = host
        self.participants = []
        self.active = False

    def start(self):
        self.active = True
        print(f"Conference started by {self.host}")

    def add(self, participant):
        if self.active:
            self.participants.append(participant)
            print(f"{participant} joined")

    def remove(self, participant):
        if participant in self.participants:
            self.participants.remove(participant)
            print(f"{participant} left")

    def end(self):
        self.active = False
        print(f"Conference ended by {self.host}")

# Example usage
conf = VideoConference("Alice")
conf.start()
conf.add("Bob")
conf.add("Charlie")
conf.remove("Bob")
conf.end()
